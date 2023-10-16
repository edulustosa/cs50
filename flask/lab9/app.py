import os

import sqlite3
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Configure CS50 Library to use SQLite database
def db_insert(sql_query, name, month, day):
    conn = sqlite3.connect("birthdays.db")
    cursor = conn.cursor()

    cursor.execute(
        sql_query,
        (
            name,
            month,
            day,
        ),
    )
    conn.commit()

    conn.close()


def db_data(sql_query):
    conn = sqlite3.connect("birthdays.db")
    cursor = conn.cursor()

    cursor.execute(sql_query)
    birthday_data = cursor.fetchall()

    conn.close()
    return birthday_data


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        db_insert(
            "INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)",
            name,
            month,
            day,
        )

        return redirect("/")

    else:
        # Display the entries in the database on index.html
        data = db_data("SELECT name, month, day FROM birthdays")

        return render_template("index.html", data=data)


if __name__ == "__main__":
    app.run(debug=True)
