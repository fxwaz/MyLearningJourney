/*

    Call By Value:
    - The function creates a new variable and copies the value into it
    - The new variable has its own memory address
    - Any changes inside the function do NOT affect the original variable

    Example:

        void Function1(int x)

        a = 10          x = 10
        0x1000          0x2000
        Original        Copy

        After x++:
        a = 10          x = 11

        When the function ends x is removed from memory


    Call By Reference:
    - The function does NOT create a separate copy of the value
    - The parameter becomes another name (alias) for the original variable
    - Both names refer to the same value in memory
    - Any changes through the reference affect the original variable

    Example:

        void Function1(int& x)

        Names: a, x
              |
              v
        +-----------+
        |    10     |
        +-----------+
          0x1000

        After x++:

        Names: a, x
              |
              v
        +-----------+
        |    11     |
        +-----------+
          0x1000

        So:
        By Value     = Copy of the value
        By Reference = Another name for the original variable


    Address Operator (&):

        int a = 10;

        a  -> Returns the value of a
        &a -> Returns the memory address of a

        Example:
        cout << a;   // 10
        cout << &a;  // Memory address of a
*/