# Validators

A form with validators for the fields.

Project creator: Alexander Yershov
ID: 319140943

The application creates a standard form for future hotel guests that wish to make a booking.
Every field contains a validator (with the option for more than a single validator) that checks whether
the content entered by the user is valid or not. 

The code contains following objects:
Form- an object of the entire form. Contains a vectors of fields (BaseField pointers), form validators and error messages. Responsible for
initiating (calling the members' functions) form tasks such as filling the form, validating the form and printing it.
Field- a template class representing a single field in the form. Has an input function for the user to input the required content of the field
and function that checks whether the entered cotent is valid.
BaseField- an abstact non-template super-class of Field. Required for storing the fields in a non-template vector.

Validators:

FieldValidators: (a template super class for field validators to inherit from, abstract)
DateValidator- checks if the date is valid by checking its' format first and then checking whether the date passed.
IDValidator- checks if ID is valid using the check digit algorithem.
NoDigitValidator- checks that the string doesn't contain any digits.
NonNegativeValidator- checks that the number is not negative.
NotGreaterThanValidator- checks that the content is not greater than a specific limit.
RangeValidator- checks that content is within a certain range.

FormValidator: (a non-template super class for form validators to inherit from, abstract)
RoomValidator- checks if number of people staying is the fits the amount of beds booked in the hotel.
SumValidator- checks if amount of children and adults is the same as amount of people.

main: Responsible for creating all the fields and and managing the application.
Main data bases:
Form holding the field, error messages and validators is the main data base of the application.