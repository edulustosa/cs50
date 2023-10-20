from flask import (
    Flask,
    flash,
    redirect,
    render_template,
    url_for,
    get_flashed_messages,
    request,
    session,
)
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from functools import wraps

import database

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """

    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)

    return decorated_function


@app.route("/")
@login_required
def index():
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        # Ensure username and password was submitted
        if not username:
            flash("Must provide a username")
            return render_template("login.html", alert="danger")
        elif not password:
            flash("Must provide a password")
            return render_template("login.html", alert="danger")

        # Query database for username
        rows = database.get_data("SELECT * FROM users WHERE username = ?", (username,))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0][2], password):
            flash("Invalid username and/or password")
            return render_template("login.html", alert="danger")

        # Remember which user has logged in
        session["user_id"] = rows[0][0]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Get user information
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            flash("Must provide a username")
            return render_template("register.html", alert="danger")
        elif not password:
            flash("Must provide a password")
            return render_template("register.html", alert="danger")
        elif not confirmation:
            flash("Must provide a confirmation")
            return render_template("register.html", alert="danger")
        elif password != confirmation:
            flash("Password do not match")
            return render_template("register.html", alert="danger")

        rows = database.get_data("SELECT * FROM users WHERE username = ?", (username,))
        if len(rows) != 0:
            flash("Username already exists")
            return render_template("register.html", alert="danger")

        database.commit(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            (
                username,
                generate_password_hash(password),
            ),
        )
        user = database.get_data("SELECT * FROM users WHERE username = ?", (username,))

        session["user_id"] = user[0][0]

        return redirect("/")
    else:
        return render_template("register.html")


if __name__ == "__main__":
    app.run(debug=True)
