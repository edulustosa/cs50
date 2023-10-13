from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    # name = request.args.get("name", "world")
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        # In POST methods it's used request.form
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)
    # return render_template("index.html", name=name)


# @app.route("/greet", methods=["POST"])
# def greet():
#     name = request.args.get("name", "world")

#     return render_template("greet.html", name=name)


if __name__ == "__main__":
    app.run(debug=True)
