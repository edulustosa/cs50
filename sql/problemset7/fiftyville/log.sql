-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT
  description
FROM
  crime_scene_reports
WHERE
  MONTH = 7
  AND DAY = 28
  AND street = 'Humphrey Street';

-- Description: Theft of the CS50 duck took place at 10:15 am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time - each of their interview transcripts mentions the bakery.
-- Littering took place at 16:36. No known witnesses.

-- Find the transcriptions of the bakery
SELECT
  name,
  transcript
FROM
  interviews
WHERE
  MONTH = 7
  AND DAY = 28;

-- | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Find the license_plate from the thief
SELECT
  activity,
  people.license_plate,
  passport_number,
  name
FROM
  people
  JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE
  MONTH = 7
  AND DAY = 28
  AND HOUR = 10
  AND MINUTE >= 15
  AND MINUTE <= 25;

-- Suspects:

-- +----------+---------------+---------+
-- | activity | license_plate |  name   |
-- +----------+---------------+---------+
-- | exit     | 5P2BI95       | Vanessa |
-- | exit     | 94KL13X       | Bruce   |
-- | exit     | 6P58WS2       | Barry   |
-- | exit     | 4328GD8       | Luca    |
-- | exit     | G412CB7       | Sofia   |
-- | exit     | L93JTIZ       | Iman    |
-- | exit     | 322W7JE       | Diana   |
-- | exit     | 0NTHK55       | Kelsey  |
-- +----------+---------------+---------+

-- Find among these suspects who withdrew some money
SELECT
  name,
  transaction_type
FROM
  people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
  MONTH = 7
  AND DAY = 28
  AND atm_location = 'Leggett Street';

-- Main suspects:
-- Bruce
-- Diana
-- Iman
-- Luca

SELECT
  phone_number
FROM
  people
WHERE
  license_plate = 'L93JTIZ';

-- (367) 555-5533 Bruce
-- (770) 555-1861 Diana
-- (829) 555-5269 Iman
-- (829) 555-5269 Luca

-- Check the phone calls
SELECT
  caller,
  receiver
FROM
  phone_calls
WHERE
  MONTH = 7
  AND DAY = 28
  AND caller = '(829) 555-5269'
  AND duration < 60;

-- Bruce
-- (367) 555-5533 | (375) 555-8161
-- Diana
-- (770) 555-1861 | (725) 555-3243

-- Check possible accomplices
SELECT
  name
FROM
  people
WHERE
  phone_number = '(725) 555-3243';

-- Bruce passport: 5773159633 | Robin
-- Diana passport: 3592750733 | Philip

-- Check if Bruce or Diana caught a flight on day 29
SELECT
  *
FROM
  flights
  JOIN passengers ON passengers.flight_id = flights.id
WHERE
  passport_number = 5773159633
  AND MONTH = 7
  AND DAY = 29;

-- Diana caught a flight at 16:00, and Bruce caught one at 8:20. The witness said the thief was planning to take the earliest flight, so it's Bruce.

-- Find the city they fled to
SELECT
  city
FROM
  airports
WHERE
  id = 4;

-- New York City
