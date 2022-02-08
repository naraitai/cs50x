"""---------------------------------
Task 2 of 2

Brief
- Build a flask web application to allows users to buy and sell stocks (demo)
- Complete register
    - Require username
    - Require password
    - Submit data via POST to /register
    - Log user in
- Complete quote
    - Require user to input a stock's symbol
    - Submit via POST to /quote
- Complete buy
    - Require user to input a stock's symbol
    - Require user to input number of stocks
    - Submit via POST to /buy
    - Lookup stock price
    - Check amount of cash user has left
    - Add data to database
    - Return apology if can't afford it
- Complete index
    - Display HTML table summarising 
        - Owned stocks and number of shares
        - Current price of stock
        - Total value
        - Current cash balance
        - Grand total (cash plus stock value)
- Complete sell
    - Allow users to sell stocks
    - Require a stock's symbol
    - Require number of shares to sell
    - Submit via POST to /sell
- Complete history
    - Display HTML table summarising all transactions
    - Make clear whether stock was bought or sold
    - Include stock's symbole, purchase/sale price and number of shares
- Implement a minimum of one personal touch (implement change password feature)

Distribution code
- favicon
- styles.css
- apology.html
- layout.html
- login.html
- finance.db
- requirement.txt
- helpers.py
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
from flask import Flask, flash, redirect, render_template, request, session, abort
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import timedelta

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = True
app.config["PERMANENT_SESSION_LIFETIME"] = timedelta(seconds=5)
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

print(app.config["SESSION_FILE_DIR"])

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    abort(500)
    """Show portfolio of stocks"""
#>>>>>>Distribution code end<<<<<<

    # Query for index table contents
    portfolio = db.execute("SELECT * FROM portfolio WHERE user_id = ?", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # Loop to find total value of holdings
    total = 0
    count = 0
    for entry in portfolio:
        total += lookup(portfolio[count]["symbol"])["price"] * portfolio[count]["shares"]
        count += 1

    # Pass index table contents to index page
    return render_template("index.html", portfolio=portfolio, cash=cash, lookup=lookup, total=total)

#>>>>>>Distribution code start<<<<<<
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
#>>>>>>Distribution code end<<<<<<

    # User reacher route via POST
    if request.method == "POST":

        # Store user input
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")

        # Store current stock information
        stock = lookup(symbol)

        # Ensure user input valid
        if not symbol:
            return apology("please enter a stock symbol")

        elif not stock:
            return apology("that stock does not exist")

        elif not shares:
            return apology("please enter shares")

        elif not shares.isdigit():
            return apology("please enter a positive whole number")

        # Valid user input
        else:

            # Ensure user has enough cash for transaction
            cost = stock["price"] * int(shares)
            cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

            if cost > cash:
                return apology("not enough cash")

            # User has sufficient cash
            else:

                # If no matching entry in portfolio create new entry, else update matching entry
                record = db.execute("SELECT id FROM portfolio WHERE symbol = ?", symbol)

                if not record:
                    db.execute("INSERT INTO portfolio (user_id, symbol, name, shares) VALUES(?, ?, ?, ?)",
                               session["user_id"], symbol, stock["name"], shares)
                else:
                    db.execute("UPDATE portfolio SET shares = shares + ? WHERE symbol = ?",
                               shares, symbol)

                record = db.execute("SELECT id FROM portfolio WHERE symbol = ?", symbol)

                # Record transaction
                db.execute("INSERT INTO transactions (user_id, portfolio_id, symbol, shares, price, type) VALUES(?, ?, ?, ?, ?, ?)",
                           session["user_id"], record[0]["id"], symbol, shares, stock["price"], "buy")

                # Update cash
                db.execute("UPDATE users SET cash = (cash - ?) WHERE id = ?", cost, session["user_id"])
                return redirect("/")

    # User reached route via GET
    else:
        return render_template("/buy.html")

#>>>>>>Distribution code start<<<<<<
@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
#>>>>>>Distribution code end<<<<<<

    # Query transaction table for user transactions
    history = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])

    # Pass transactions to table history page
    return render_template("history.html", history=history)


@app.route("/account", methods=["GET", "POST"])
@login_required
def account():
    """Change username or password"""

    # User reached route via POST
    if request.method == "POST":

        # Ensure current and new username input
        username = request.form.get("username")
        new_username = request.form.get("new_username")

        if username and new_username:

            # Ensure current username is correct and update
            if username == db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[0]["username"]:
                db.execute("UPDATE users SET username = ?", new_username)

                success = "Username changed"

                return render_template("account.html", success=success)

            else:
                return apology("username incorrect")

        # Ensure current and new password input
        password = request.form.get("password")
        new_password = request.form.get("new_password")

        if password and new_password:

            # Ensure current password is correct and update
            check = db.execute("SELECT hash FROM users WHERE id = ?", session["user_id"])[0]["hash"]
            if check_password_hash(check, password):
                db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(new_password), session["user_id"])

                success = "Password changed"

                return render_template("account.html", success=success)

            else:
                return apology("password incorrect")

        else:
            return apology("Enter info to change")

    # User reacher route via GET
    else:
        user = db.execute("SELECT username, hash FROM users WHERE id = ?", session["user_id"])

        password = check_password_hash(user[0]["hash"], user[0]["hash"])

        return render_template("account.html", user=user, password=password)

#>>>>>>Distribution code start<<<<<<
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

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

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
#>>>>>>Distribution code end<<<<<<

    # User reached route via POST (submitting form via POST)
    if request.method == "POST":

        stock = lookup(request.form.get("symbol"))

        # Check user input
        if not request.form.get("symbol"):
            return apology("Please enter a stock symbol")

        elif not stock:
            return apology("That stock does not exist")

        # Pass stock information to quoted page
        else:
            return render_template("/quoted.html", stock=stock)

    # User reached route via GET (by clicking linke or via redirect)
    else:
        return render_template("/quote.html")

#>>>>>>Distribution code start<<<<<<
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
#>>>>>>Distribution code end<<<<<<

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Store user input
        username = request.form.get("username")
        password = request.form.get("password")

        # Ensure username and password submitted
        if not username:
            return apology("please enter a username")

        elif not password:
            return apology("please enter a password")

        # Ensure username is unique
        elif db.execute("SELECT username FROM users WHERE username = ?", username):
            return apology("that username already exists")

        # Ensure password / confirmation match
        elif password != request.form.get("confirmation"):
            return apology("passwords did not match")

        # Register user
        else:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, generate_password_hash(password))

            return redirect("/login")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

#>>>>>>Distribution code start<<<<<<
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
#>>>>>>Distribution code end<<<<<<

    # User reached route via POST
    if request.method == "POST":

        # Store user input
        shares = int(request.form.get("shares"))
        symbol = request.form.get("symbol")

        # Store stock information
        stock = lookup(symbol)

        # Check user input
        if not symbol:
            return apology("please enter a stock symbol")

        elif not stock:
            return apology("that stock does not exist")

        elif not shares:
            return apology("please enter shares")

        elif shares <= 0:
            return apology("please enter a positive number")

        # Valid user input
        else:
            count = db.execute("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)

            # Check user has sufficient shares
            if not count:
                return apology("you do not own any of that stock")
            elif shares > count[0]["shares"]:
                return apology("not enough shares")

            # User has sufficient shares
            else:
                cost = stock["price"] * shares
                record = db.execute("SELECT id FROM portfolio WHERE symbol = ?", symbol)

                # Record transaction
                db.execute("INSERT INTO transactions (user_id, portfolio_id, symbol, shares, price, type) VALUES(?, ?, ?, ?, ?, ?)",
                           session["user_id"], record[0]["id"], symbol, shares, stock["price"], "sell")

                # Update user portfolio
                db.execute("UPDATE portfolio SET shares = (shares - ?) WHERE user_id = ? AND symbol = ?",
                           shares, session["user_id"], symbol)

                db.execute("DELETE FROM portfolio WHERE shares = 0 AND user_id = ?", session["user_id"])

                # Update user cash
                db.execute("UPDATE users SET cash = (cash + ?) WHERE id = ?", cost, session["user_id"])

                return redirect("/")

    # User reached route via GET
    else:
        symbols = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])

        return render_template("/sell.html", symbols=symbols)

#>>>>>>Distribution code start<<<<<<
def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
#>>>>>>Distribution code end<<<<<<