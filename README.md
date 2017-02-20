This project is a prototype at attempting to create a more modular and maintainable project based on the signals and slots model (C++ callbacks).


The different components of a program, do not assume anything about the structure of the other components and no attempt at creating hierarchical interfaces are made. 

The communication between servers and clients in a relationship are instead done via the concepts of "Role" and "Task".
This allows for indepdent development of servers that provide a functionality and clients that want that have signals for callbacks. 


Moreover, the broker mechanism will allow for dynamic allocation of clients and servers against one another and the wiring of clients and servers is less static/global.

complete static type checking of the system is one of the main objective of this project.
