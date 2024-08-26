-- Keep a log of any SQL queries you execute as you solve the mystery.


-- Becaue i know the specific date and street where the theft happened i'm looking for additional information in the crime_scene_reports table
SELECT street, year, month, day, description FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND year = 2023
AND month = 7
AND day = 28;

-- Checking the interviews for the date mentioned looking for any mentions of bakery
SELECT * FROM interviews
WHERE transcript LIKE '%bakery%';
-- 1. The Thief left within 10 minutes 10:15 - 10:25
-- 2. The thief got recognized withdrawing money from the atm at Legget Street earlier that morning
-- 3. The thief made a phone call to his accomplice that lasted for less than 60 seconds and told his accomplice to book the earliest flight out on the 29th

-- Since the theft took place at 10:15 am and some interview mentioned the thief entering a car sometime within 10minutes
-- I'm checking for license plate's
SELECT license_plate FROM bakery_security_logs
WHERE day = 28
AND activity ='exit'
AND hour = 10
AND minute > 15
AND minute < 25;
/* The license plates of the possible suspects.
+---------------+
| license_plate |
+---------------+
| 5P2BI95       |
| 94KL13X       |
| 6P58WS2       |
| 4328GD8       |
| G412CB7       |
| L93JTIZ       |
| 322W7JE       |
| 0NTHK55       |
+---------------+
*/
-- Checking the license plate owners of the possible getaway vehicle
SELECT name FROM people
WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND activity = 'exit'
    AND hour = 10
    AND minute > 15
    AND minute < 25
);
 /*
+---------+
|  name   |
+---------+
| Vanessa |
| Barry   |
| Iman    |
| Sofia   |
| Luca    |
| Diana   |
| Kelsey  |
| Bruce   |
+---------+
 */

-- Someone mentioned seeing the thief earlier that day withdrawing money on Legget Street
-- Checking for everone withdrawing money at day
 SELECT * FROM atm_transactions
 WHERE day = 28
 AND atm_location = 'Leggett Street';
 SELECT name FROM people
 WHERE id IN
 (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE atm_location = 'Leggett Street'
        AND day = 28
        and transaction_type = 'withdraw'
    )
);
/*
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
+---------+
*/

-- Got the information from one of the interviews that the thief called someone for less than a minute just before he robbed the store
-- Getting the names from the people who called somone that day for less than 60 seconds
SELECT name FROM people
WHERE phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE duration < 60
    AND day = 28
);
/* CALLER
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   |
+---------+
*/
-- Same for receivers to find the accomplice
SELECT name FROM people
WHERE phone_number IN
(
    SELECT receiver
    FROM phone_calls
    WHERE duration < 60
    AND day = 28
);
/* RECEIVER
+------------+
|    name    |
+------------+
| James      |
| Larry      |
| Anna       |
| Jack       |
| Melissa    |
| Jacqueline |
| Philip     |
| Robin      |
| Doris      |
+------------+
*/
-- Checking all the flights on the 29th leaving from Fiftyville ordering to find the earliest
-- Flight with id 36 is the earliest one to leave
SELECT id FROM flights
WHERE origin_airport_id =
(
    SELECT id FROM airports
    WHERE city= 'Fiftyville'
)
AND day, minute = 29
ORDER BY hour LIMIT 1;

-- To see where the suspect is going to
-- Flies to New York City
SELECT city FROM airports
WHERE id =
(
    SELECT destination_airport_id
    FROM flights
    WHERE id = 36
);


