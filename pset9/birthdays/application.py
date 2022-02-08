"""---------------------------------
Task 1 of 2

Brief
- Build a flask web application to keep track of friends' birthdays
    
Distribution code
- styles.css
- index.html (boilerplate)
- birthdays.db
- Shown as follows 
    >>>>>Distribution code start<<<<<
    >>>>>>Distribution code end<<<<<<

None Standard Libraries
cs50

Key concept:
- Basic HTML, CSS and JavaScript
-----------------------------------"""

#>>>>>Distribution code start<<<<<
import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
#>>>>>>Distribution code end<<<<<<

        # Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")


        if request.form.get("save"):
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)
        elif request.form.get("delete"):
            db.execute("DELETE FROM birthdays WHERE name = ? AND month LIKE ? AND day = ?", name, month, day)
        elif request.form.get("edit"):
            db.execute("UPDATE birthdays SET month = ?, day = ? WHERE name = ?", month, day, name)

        return redirect("/")

    else:

        #Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


