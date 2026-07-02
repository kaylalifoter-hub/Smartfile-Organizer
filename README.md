


📁 SmartFile Organizer

📌 Description

SmartFile Organizer is a C application that automatically organizes files inside a selected directory based on their file extensions. Once the user provides a folder path, the program scans the directory, creates categorized folders if they do not exist, and moves each file into its appropriate folder.

It also includes a smart background mode that continuously monitors the folder for newly added files and automatically organizes them in real time.




⚙️ How It Works

1. User enters a folder path.


2. The program performs an initial cleanup of existing files.


3. Files are sorted into folders based on their extensions.


4. The program enters Smart Background Mode.


5. It continuously scans the folder at intervals.


6. Any newly added file is automatically detected and moved.


7. The process repeats endlessly until the program is closed.






📂 Folder Structure Example

After running the program:

Your Folder/
│
├── Documents/
├── Images/
├── Music/
├── Videos/
├── Others/

Each file is automatically placed into the correct folder based on type.




✨ Features

Automatic file sorting by extension

Real-time folder monitoring

Background scanning mode

Auto-creation of category folders

Immediate cleanup of existing files

Lightweight and fast execution

Continuous organization without user input





🛠️ Technologies Used

C Programming Language

File Handling (stdio.h)

Directory Management (dirent.h, filesystem-style logic)

Windows Sleep function (for periodic scanning loop)





▶️ How to Run

1. Open the project in Code::Blocks or any C compiler.


2. Compile the program.


3. Run the executable.


4. Paste the folder path when prompted.


5. Leave the console open to enable background monitoring.






🧠 Notes

The program runs continuously until manually closed.

It does not delete or modify files, only moves them.

Best used for Downloads, Desktop, or project folders.

Designed for Windows environments.





👨‍💻 Author

Lifoter Kayla
C-based automation project for intelligent file organization and real-time folder monitoring.




