This project is a prototype at attempting to create a more modular and maintainable, not to mention more efficient project based on the signals and slots model (C++ callbacks).


The different components of a program, do not assume anything about the structure of the other components and no attempt at creating hierarchical interfaces are made. The idea is not to have a controller that parses the string messages and hooks up signals with slots, as is done in Android, etc, because they are both error-prone and not efficient. We instead introduce a "broker" that the components register themselves with and have their functions and delegates directly connected so that the additional routing in a controller is avoided.

The communication between servers and clients in a "relationship" are done via the concepts of "Role" and "Task".
This allows for indepdent development of servers that provide a functionality and clients that want to trigger these callback methods.


Moreover, the broker mechanism will allow for dynamic allocation of clients and servers against one another and the wiring of clients and servers is less static/global.

complete static type checking of the system is one of the main objective of this project.
