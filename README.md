# E-Waste Management System

A C-based console application designed to automate electronic waste segregation, disposal method assignment, and pickup request processing. Developed as a Data Structures Laboratory mini-project, this system replaces manual record-keeping with structured data management to ensure safe handling of hazardous components and organized disposal tracking.

---

## 📌 Project Overview

Improper disposal of electronic waste—such as mixing toxic batteries with general plastics—poses severe environmental and safety hazards. The **E-Waste Management System** provides an organized mechanism to:
- Register electronic waste items by ID, name, and weight.
- Automatically classify items into hazard categories.
- Assign verified, safe disposal protocols.
- Buffer and process pickup requests in First-In-First-Out (FIFO) sequence.
- Persist data across sessions using flat-file storage.

---

## 🛠️ Data Structures Implemented

| Data Structure | Implementation | Purpose in System |
| :--- | :--- | :--- |
| **Singly Linked List** | Dynamic node allocation (`struct Item*`) | Stores e-waste inventory dynamically in memory, allowing unbounded insertion and sequential traversal. |
| **Linear Queue** | Array-based (`front`, `rear` indices) | Manages pending recycler pickup requests in FIFO (First-In-First-Out) order. |
| **Structures (`struct`)** | Custom data bundle (`struct Item`) | Encapsulates item attributes: ID, name, weight, category, and disposal technique. |
| **File Handling** | Flat-file I/O (`FILE*`) | Provides persistence across program executions by syncing data to `ewaste.txt`. |

---

## ✨ Features

- **Automated Segregation:** Parses item labels and categorizes them automatically:
  - `Hazardous` (e.g., Batteries) $\rightarrow$ *Chemical Neutralization*
  - `E-Board` (e.g., Motherboards, PCBs) $\rightarrow$ *Metal Smelting*
  - `General` $\rightarrow$ *Shredding & Recycling*
- **Dynamic Inventory Display:** Formats stored records into a clean, readable tabular overview.
- **Pickup Request Queue:** Adds pending items to a request queue for authorized recyclers and dispatches them sequentially.
- **Automatic State Reload:** Automatically reads existing items from `ewaste.txt` upon application startup.

---

## 📂 Project Structure

```text
.
├── main.c          # Source code containing all modules and data structures
├── ewaste.txt      # Data persistence file (auto-generated on write)
└── README.md       # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites
- A C compiler (e.g., `gcc`, `clang`, or MinGW on Windows).

### Compilation
Compile the program using `gcc`:

```bash
gcc -o ewaste main.c
```

### Execution
Run the compiled executable:

- **Linux / macOS:**
  ```bash
  ./ewaste
  ```
- **Windows:**
  ```bash
  ewaste.exe
  ```

---

## 💻 Sample Interaction

```text
--- E-WASTE MANAGEMENT ---
1. Register Item
2. View All Items
3. Request Pickup
4. Process Pickup
5. Exit
Enter choice: 1
Enter ID, Name (no spaces), and Weight (kg): 101 Battery 1.5
Item registered successfully! Category: Hazardous | Disposal: Chemical Neutralization

--- E-WASTE MANAGEMENT ---
1. Register Item
2. View All Items
3. Request Pickup
4. Process Pickup
5. Exit
Enter choice: 2

--- Registered E-Waste Items ---
ID     Name            Weight     Category        Disposal Method          
101    Battery         1.50       Hazardous       Chemical Neutralization  

--- E-WASTE MANAGEMENT ---
1. Register Item
2. View All Items
3. Request Pickup
4. Process Pickup
5. Exit
Enter choice: 3
Enter Item ID to queue for pickup: 101
Item 101 added to pickup queue.

--- E-WASTE MANAGEMENT ---
1. Register Item
2. View All Items
3. Request Pickup
4. Process Pickup
5. Exit
Enter choice: 4
Processed pickup for Item ID: 101
```

---

## 📜 License
This project is open-source and intended for educational purposes under the [MIT License](LICENSE).
