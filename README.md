# InputWizard

## Content

- [📄 Overview](#overview)
- [✨ Features](#features)
    - [🗂️File Management Operations](#file-management-operations)
- [🔧 Usage Instructions](#usage-instructions)

---

## Overview

InputWizard is a C++ command-line tool designed for efficient file management and text processing. It provides a simple interface for users to interact with files through various options.

---

## Features

#### Commands
Type `help` for available commands:
``` cpp
    Available options:
    [1] cnf.      {Create new file}
    [2] of.       {Open File}
    [3] ls.       {show list of str}
    [4] cl.       {clear list of str}
    [5] clear.    {clear terminal}
```
### File Management Operations
#### 📁 Create Files
- Create new files using previously typed strings

#### 📖 Open Files
- Open existing files and display contents
- Show the number of lines used in the file

#### 📊 List Strings
- Display the previously typed strings along with their counts

#### 🚮 Clear List
- Remove all typed strings from memory

#### ⏪ Clear Terminal
- Clear the command line for better visibility

## To Do List

1. `openFile()` function
   - fix amount of lines 

2. Develop `deleteFile()` function
   - Ensure safe deletion

3. Create `editFile()` function
   - Implement text editing capabilities
   
---

## Usage Instructions

1. Clone the repository
2. Compile with `make`
3. Run the program
