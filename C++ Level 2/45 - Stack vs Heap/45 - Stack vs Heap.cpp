/*

 When a program runs its memory is divided into different areas:


                    PROGRAM MEMORY
              ┌─────────────────────────┐
              │                         │
              │          HEAP           │
              │                         │
              │     Dynamic Memory      │
              │      new / delete       │
              │                         │
              ├─────────────────────────┤
              │                         │
              │         STACK           │
              │                         │
              │    Local Variables      │
              │    Function Calls       │
              │    Local Pointers       │
              │                         │
              ├─────────────────────────┤
              │                         │
              │    STATIC / GLOBAL      │
              │                         │
              │    Global Variables     │
              │    Static Variables     │
              │                         │
              ├─────────────────────────┤
              │                         │
              │      PROGRAM CODE       │
              │                         │
              │ Executable Instructions │
              │     (Machine Code)      │
              │                         │
              └─────────────────────────┘


 ------------------------------------------------------------

 Example:

 int* ptr = new int;


                 STACK                         HEAP

        ┌──────────────────┐          ┌──────────────────┐
        │       ptr        │          │                  │
        │                  │          │       int        │
        │      0x500 ──────┼─────────►│                  │
        │                  │          │  Address: 0x500  │
        └──────────────────┘          └──────────────────┘
                 │                             │
                 │                             │
                 │                             └─ Dynamically allocated
                 │                                memory is stored here
                 │
                 └─ The pointer itself is a
                    local variable so it is
                    stored on the Stack


 What happens step by step?

 1. int* ptr;
    A local pointer called "ptr" is created on the Stack

 2. new int;
    Memory for one integer is allocated on the Heap

 3. new returns the address of that memory.
    Example address: 0x500

 4. ptr stores that address

       ptr = 0x500

 5. We can access the Heap memory through the pointer

       *ptr = 100;


                 STACK                         HEAP

        ┌──────────────────┐          ┌──────────────────┐
        │       ptr        │          │       100        │
        │      0x500 ──────┼─────────►│                  │
        └──────────────────┘          │  Address: 0x500  │
                                      └──────────────────┘


 6. When the dynamically allocated memory is no longer needed:

       delete ptr;

    The memory on the Heap is released.


                 STACK                         HEAP

        ┌──────────────────┐
        │       ptr        │                FREED
        │      0x500 ──────┼─────────────── X
        └──────────────────┘


 ------------------------------------------------------------

 IMPORTANT:

 Stack:
 - Stores local variables and function call information
 - Memory is managed automatically
 - Local variables are automatically destroyed when their scope ends

 Heap:
 - Used for dynamic memory allocation at runtime
 - Memory is allocated using "new"
 - "new" returns the address of the allocated memory
 - A pointer stores that address
 - Memory allocated with "new" must be released using "delete"
 - Arrays allocated with "new[]" must be released using "delete[]"


              STACK                         HEAP

        Managed Automatically         Managed Manually
                 │                           │
                 │                           │
          Local Variables              Dynamic Memory
          Function Calls               new / new[]
          Local Pointers               delete / delete[]

*/