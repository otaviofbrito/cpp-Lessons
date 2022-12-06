##Application developed with dynamic allocation, using linked list to allocate vehicles in a database.
Firstly the application reads each line of the data file and allocate it to a linked list, with the data allocated it's possible to sort the vehicles alphabetically by its license plate.

#There are few options that the user can dig in:

1 - Search vehicle by license plate: Search the inputted license plate in the database, if the vehicle is already stored, the remove option will trigger allowing user to delete the searched vehicle from the database, otherwise a message will show saying the vehicle was not found.

2 - Insert car: if the vehicle is not stored in database the user can store it by typing its specs, if the vehicle is already stored a warning message will show.

3- Sort vehicles by license plate: Sort all vehicles alphabetically by license plate based on the main list.

4- Stack of vehicles with hydraulic steering: Search for each vehicle that has hydraulic steering system in the main list and stores them in a stack.

5- Queue of vehicles with automatic transmission: Search for each vehicle that has hydraulic steering system in the main list and stores them on a queue.

6- Save changes: Overwrite the data file based on the currently main list.

7- Main list log: The main list log will be printed on terminal.

8- Quit: quit the application deallocating every struct created.