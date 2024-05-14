# LAB_C.1

# **Integer Overflow Vulnerabilities:**

The goal of this Lab is to demonstrate **Integer Overflow Vulnerabilities** in software development.

### **What is Integer Overflow?**

Integer overflow occurs when an arithmetic operation results in a value that exceeds the maximum representable value for that data type. In simpler terms, it happens when the result of adding, subtracting, multiplying, or dividing two integers is too large to be stored in the variable's data type. For example, if an 8-bit unsigned integer is incremented beyond 255, it will "overflow" back to 0.

### **Reason Behind Integer Overflow**

Integer overflow typically arises due to improper validation of input data or incorrect assumptions about the range of possible values during arithmetic operations. It can lead to unexpected behavior, including crashes, memory corruption, or security vulnerabilities.

### **How to Exploit Integer Overflow**

Exploiting an integer overflow vulnerability often involves manipulating input data to trigger an overflow condition, causing the program to behave unexpectedly. Attackers may leverage this vulnerability to bypass security mechanisms, gain unauthorized access, or execute arbitrary code.

For example, an attacker might craft input data to cause an overflow in a buffer size calculation, leading to a buffer overflow vulnerability and potentially enabling them to execute malicious code

### **Mitigation of Integer Overflow Vulnerabilities**

1. **Input Validation**: Always validate user input to ensure it falls within acceptable ranges.
2. **Use Safe Data Types**: Utilize data types or libraries that automatically handle overflow conditions, such as BigInt in JavaScript or BigInteger in Java.
3. **Bounds Checking**: Implement bounds checking to ensure arithmetic operations do not result in overflow.
4. **Static Code Analysis**: Employ static code analysis tools to detect potential integer overflow vulnerabilities during the development phase.
5. **Code Review**: Conduct thorough code reviews to identify and address any instances of unsafe arithmetic operations.

### **Automated Tools for Detection**

Several automated tools are available for detecting integer overflow vulnerabilities:

- **CodeSonar**: CodeSonar is a static analysis tool that can identify integer overflow vulnerabilities during the development phase by analyzing source code.
- **Coverity**: Coverity's static analysis tool can detect integer overflow vulnerabilities by analyzing code for unsafe arithmetic operations.
- **AFL (American Fuzzy Lop)**: AFL is a fuzzer that can be used to test software for integer overflow vulnerabilities by generating inputs to trigger overflow conditions.
- **Valgrind**: Valgrind's AddressSanitizer tool can detect integer overflow vulnerabilities at runtime by instrumenting binaries to check for overflow conditions.

---

# LAB SETUP

Run the below command to download docker image

```bash
docker pull phenix28/flag_exchange_app
```

Now run this command to run the docker container. 

```bash
docker run -it --rm -p 9000:9000  phenix28/flag_exchange_app
```

The app is running on PORT 9000. you have to exploit it and find the flag.

Connect the app through netcat or telnet

![Untitled](LAB_C%201%20655174e9c68647c588b0843e9d9be29e/Untitled.png)

### For the Source code analysis.

This is the GitHub repo you have to exploit it locally first and then try to exploit the docker container. The local code base contains Fake Flag.

![Untitled](LAB_C%201%20655174e9c68647c588b0843e9d9be29e/Untitled%201.png)

```bash
git clone https://github.com/Pkhuyar/Lab_3
```

Compile the code with

```bash

gcc flag_exchange.c -o flag_exchange
```

# Solution

 In C, when dealing with integer overflow, if the product of two integers exceeds the maximum value that can be stored in an integer (typically 2,147,483,647 for a 32-bit signed integer), it wraps around and results in an unexpected value.

1. Calculate the maximum value for an integer on your system.
2. Input a large number such that the product with 900 causes an integer overflow and results in a negative or very small positive number.

Given that 900 * number_flags needs to overflow, choose a number such that the multiplication exceeds the maximum value of an integer

```c
// We have to exploit the below logic 
 if (number_flags > 0)
                {
                    int total_cost = 0;
                    total_cost = 900 * number_flags;
                    printf("\n\033[1;33mThe final cost is: %d\n\033[0m", total_cost);

                    if (total_cost <= account_balance)
                    {
                        account_balance = account_balance - total_cost;
                        printf("\n\033[1;35mYour current balance after transaction: %d\n\n\033[0m", account_balance);
                    }
```

### **Exploiting the Overflow**

When you run the program, follow these steps:

1. Select option 2 to buy flags.
2. Choose option 1 to buy "Defintely not the flag Flag".
3. Enter the large number **22147483647** for the quantity of flags.

This should cause an overflow, making **`total_cost`** a negative or very small positive value, allowing you to proceed without depleting the account balance

![Untitled](LAB_C%201%20655174e9c68647c588b0843e9d9be29e/Untitled%202.png)

![Untitled](LAB_C%201%20655174e9c68647c588b0843e9d9be29e/Untitled%203.png)

Flag

![Untitled](LAB_C%201%20655174e9c68647c588b0843e9d9be29e/Untitled%204.png)