def factorial_iterative(n):
    stack = []
    result = 1
    while n > 0:
        stack.append(n)  # Push onto stack
        n -= 1
    while stack:
        result *= stack.pop()  # Pop and multiply
    return result

print(factorial_iterative(4))  # Output: 24
