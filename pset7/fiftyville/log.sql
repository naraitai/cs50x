-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Details:
    -- Crime: Theft of CS50 duck
    -- Date: July 28 2020
    -- Place: Chamberlin Street courthouse
    -- Time: 10:15am

    -- 10 minutes after theft suspect got in car and drove away (Ruth - witness)

-- Thief: Ernest

-- Destination: Heathrow Airport

-- Accomplice: Berthold


-- Database structure and information.
.tables
    -- airports / crime_scene_reports / people / atm_transactions / flights / phone_calls / bank_accounts / interviews / courthouse_security_logs / passengers

.schema crime_scene_reports
    -- id INTEGER / year INTEGER / month INTEGER / day INTEGER / street TEXT / description TEXT / PRIMARY KEY(id)

.schema interviews
    -- id INTEGER / name TEXT / year INTEGER / month INTEGER / day INTEGER / transcript TEXT / PRIMARY KEY(id)

.schema courthouse_security_logs
    -- id INTEGER / year INTEGER / month INTEGER day INTEGER / hour INTEGER / minute INTEGER / activity TEXT / license_plate TEXT / PRIMARY KEY(id)

.schema atm_transactions
    --  id INTEGER / account_number INTEGER / year INTEGER / month INTEGER / day INTEGER / atm_location TEXT / transaction_type TEXT / amount INTEGER / PRIMARY KEY(id)

.schema flights
    -- id INTEGER / origin_airport_id INTEGER / destination_airport_id INTEGER / year INTEGER / month INTEGER / day INTEGER / hour INTEGER / minute INTEGER / PRIMARY KEY(id)
    -- FOREIGN KEY(origin_airport_id) REFERENCES airports(id) / FOREIGN KEY(destination_airport_id) REFERENCES airports(id)

.schema airports
    --  id INTEGER / abbreviation TEXT / full_name TEXT / city TEXT / PRIMARY KEY(id)

.schema bank_accounts
    -- account_number INTEGER / person_id INTEGER / creation_year INTEGER / FOREIGN KEY(person_id) REFERENCES people(id)

.schema people
    -- id INTEGER / name TEXT / phone_number TEXT / passport_number INTEGER / license_plate TEXT / PRIMARY KEY(id)

.schema passengers
    -- flight_id INTEGER / passport_number INTEGER / seat TEXT / FOREIGN KEY(flight_id) REFERENCES flights(id)

.schema phone_calls
    -- id INTEGER / caller TEXT / receiver TEXT / year INTEGER / month INTEGER / day INTEGER / duration INTEGER / PRIMARY KEY(id)

-- Description of crime
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";
    -- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
    -- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- Check witness interviews for further details
SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
    -- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
    --        If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

    -- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
    --          I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

    -- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
    --           In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    --           The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Parking lot CCTV (Ruth)
SELECT hour, minute, activity, license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;
    -- 10 | 16 | exit | 5P2BI95
    -- 10 | 18 | exit | 94KL13X
    -- 10 | 18 | exit | 6P58WS2
    -- 10 | 19 | exit | 4328GD8
    -- 10 | 20 | exit | G412CB7
    -- 10 | 21 | exit | L93JTIZ
    -- 10 | 23 | exit | 322W7JE
    -- 10 | 23 | exit | 0NTHK55

-- Earlier suspect used ATM on Fifer Street ATM (Eugene)
SELECT * FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street";
    -- Accoutn No. / Amount
    -- 28500762 / 48
    -- 28296815 / 20
    -- 76054385 / 60
    -- 49610011 / 50
    -- 16153065 / 80
    -- 25506511 / 20
    -- 81061156 / 30
    -- 26013199 / 35

-- Overheard conversation about taking earliest flight out of Fiftyville on 29/07 (Raymond). What is earliest flight?
SELECT airports.full_name, flights.hour, flights.minute FROM flights JOIN airports ON flights.destination_airport_id = airports.id WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville" AND year = 2020 AND month = 7 AND day = 29) ORDER BY hour, minute;
    -- Heathrow Airport | 8:20
    -- O'Hare International Airport | 9:30
    -- San Francisco International Airport | 12:15
    -- Tokyo International Airport | 15:20
    -- Logan International Airport | 16:00

-- Find who used ATM on the day
SELECT name from people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street"));
    -- Bobby
    -- Elizabeth
    -- Victoria
    -- Madison
    -- Roy
    -- Danielle
    -- Russell
    -- Ernest
    -- Robert

--Find who owns the cars that left the courthouse after the theft
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25);
    -- Patrick
    -- Amber
    -- Elizabeth
    -- Roger
    -- Danielle
    -- Russell
    -- Evelyn
    -- Ernest

-- People who both used ATM and left courthouse in time frame
    -- Danielle
    -- Elizabeth
    -- Ernest
    -- Russell

-- Check passengers on earliest flight from Fiftyville
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND destination_airport_id = (SELECT id FROM airports WHERE full_name = "Heathrow Airport"))) ORDER BY name;

-- People who used ATM, left courthouse and took earliest flight out of Fiftyville
    -- Danielle
    -- Ernest

-- Find who called on the day
SELECT caller, receiver, duration FROM phone_calls WHERE caller = (SELECT phone_number FROM people WHERE name = "Danielle") OR receiver = (SELECT phone_number FROM people WHERE name = "Danielle") AND year = 2020 AND month = 7 AND day = 28;
    -- (609) 555-5876 | (389) 555-5198 | 60

-- Who was caller and who receiver
SELECT phone_number FROM people WHERE name = "Danielle";
    -- (389) 555-5198

-- What calls under 1 minute did Danielle make?
SELECT caller, receiver, duration, year, month, day FROM phone_calls WHERE caller = (SELECT phone_number FROM people WHERE name = "Danielle") AND year = 2020 AND month = 7 AND day = 28 AND duration < 60;
    -- None

-- What calls under 1 minute did Ernest make?
SELECT caller, receiver, duration, year, month, day FROM phone_calls WHERE caller = (SELECT phone_number FROM people WHERE name = "Ernest") AND year = 2020 AND month = 7 AND day = 28 AND duration < 60;
    -- (367) 555-5533 | (375) 555-8161 | 45 | 2020 | 7 | 28

-- Who did Ernest call?
SELECT name FROM people WHERE phone_number = "(375) 555-8161";
    -- Berthold

-- Check the city that database identifies Heathrow as in
SELECT city FROM airports WHERE full_name = "Heathrow Airport";
    -- London

-- Ernest was at the ATM in Fifer Street on the day of the theft, Ernest left the courthouse shortly after the theft, Ernest made a call that was under 1 minute on the day of the theft
-- Ernest took the earliest flight from Fiftyville the day after the theft.
-- Ernest is the thief
-- Ernest's phone call was to Bethold.
-- Berthold is the accomplice.