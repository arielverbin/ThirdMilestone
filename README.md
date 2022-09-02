# KNN Using Multi-threaded Client-Server
At the prevoius assignment, we implemented a 'server-client' mechanism, so that the server will have the ability to classify the unclassified files of the client (see https://github.com/NavehUllman/AdvancedProgramming_ass2). Unfortunately, we did not use threads, so the server could only serve one client at a time. In this assignment, we extended the abilities of the server and the client.

The server will support the provision of service to several clients at the same time, along with the addition of a menu of commands that the server will offer to the client. The client will display the menu to the users, and know what is required of him in order to activate and run each command.

## Our Implementation
* **serverSrc**
The 'Server' class is no longer responsible of sending and recieving messages from the client. The Server is now only responsible for accpeting new clients, and directing them (along with a new thread) to a CLI, to start the communication. The direction to the CLI is performed by *ClientHandler* class, which is responsible for activating the CLI, and disconnecting from the server when the CLI finishes.
  * *The CLI* class provides the menu to the client. It holds a vector of *Command*'s, and executes the right one according to the client's request.
  * The *ClientHandler* class holds the relevant data for its client (such as KNN settings and files), in a class called *ClientData*.

* **clientSrc**
The 'Client' class is also no longer responsible of sending the recieving messages from the server. It is responsible for connecting to the server, and activating the *CommandHandler* class, which knows how to read messages and requests from the server, and run them.
  * Since the server should be the one deciding which services it offers, it is only logical that the client will have no clue which commands are available and what should it do to execute each one. Because if the server will decide to add, remove or change commands, this should not change a thing in the client's code. To deal with this, we implemented a diffrent way of communication between the client and the server. In a nutshell, the client will have a set of basic abilities such as priting to the screen, receiving an input, or opening a file. The CLI will send the client *instrucions* that the client will follow, in order to execute his part of each command. For example, the CLI might send `"<Please upload your local train CSV file>[screen_print][file_input][send_back]"`. The *CommandHandler* will decompose this string into a stack of instructions, and will execute them one by one.
 
 ## Constants
We were given the chance to choose constant parameters such as Port number and Buffer size.

* Buffer size: `128 bytes`, just like the prevoius assignment. The size of the buffer is considered a part of the interal implementation, and does not affect the functionality. A smaller buffer simply means that each message will be divided into more pieces.

* Timeout: `60 seconds`. If no clients connect to the server for more than 60 seconds, the server will stop accepting new clients, and wait for all active clients to disconnect. Immediately after the last client disconnects, the server will close itself.

* Port number: Just like in the prevoius assignment, we chose to give the user the option to choose a port. ([Jump to Running Instructions](#running-instructions)).

## Optimizations
Since some commands are complicated to execute, we would like to avoid re-executing them. The solution is quite simple - the ClientData will save the results of some of the commands. As long as nothing might have caused those results to change (reuploading the files or changing the KNN settings), the *ClientData* will keep storing them. Suppose that the client asks to classify the uploaded files. If the classifications stored in *ClientData* are not empty, the command will simply send the classifications from the *ClientData* to the client.  Because it means that the command was already executed. Otherwise, the command will classify the file and save the results on the *ClientData*. Reuploading files and changing the KNN settings clears those results from the *ClientData*.

## Running Instructions
1. Download the project to your local device. It can be done using the command `git clone https://github.com/arielverbin/ThirdMilestone.git` on your Terminal.
2. Open Terminal.
3. Navigate to **serverSrc** using the command `cd path/to/your/project/`, and then `cd serverSrc`.
4. Compile the server-side using the command `g++ *.cpp Commands/*.cpp ../IO/*.cpp Commands/KNN/*.cpp Commands/KNN/DistanceCalcs/*.cpp Commands/KNN/Flowers/*.cpp -std=c++11 -pthread` on your Terminal.
5. A file named *a.out* should appear. Run `./a.out [port]` to run the program, where `[port]` is the number of port you want the server to be binded to. For example, run: `./a.out 5555`.
6. Now, the Server should be running. Note that Timeout is ticking, so we recommend doing steps (7-9) before running the server.
7. Open a **new** window of Terminal.
8. Navigate to **clientSrc** using the command `cd path/to/your/project/`, and then `cd clientSrc`.
9. Compile the client-side using the command `g++ *.cpp ../IO/*.cpp -std=c++11 -pthread` on your Terminal.
10. A file named *a.out* should appear. Run `./a.out [port]` to run the client program, where `[port]` is the port that the server is binded to.
12. The client is now connected to the server, and you will see the server's menu.
13. Of course, you can connect several clients at the same time.

# Good Luck 😁
