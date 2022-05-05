# Modul-10
Final project 1
-------------------
This programm is the final project on Skillfactory "Basic constructions of C++" learning course.
It is a realization of a console multi-user chat that follows the technical issue:

1. A user can registragete in chat under defined unchangeble login, have changeble name and password.
2. A registrated user can sign in using user's name and password.
   When signed in a user can:
3. Send a text message to all other users: in a collection of messages,
   that every other user can read. Or send a personalizes text message to a particular user.
4. View a number of messages avalible for every user to read, and a number of personal messages, sent by other users.
5. A user can change his name and password.

Realisation of the programm logic
------------------------------------
The realisation relyes on four classes:
class Interface: provides comunication between a user and a chat itself. Contains all menues blocks and process user's input.
class Chat: contains a collection of users and a collection of messages, availible for every user to read.
class User: contains user's identifiers and personal collection of user's messages.
class Message: contains an information to exchange between all users. (A text and its sender and recepient)
    
