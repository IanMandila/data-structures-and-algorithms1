def summation(arr):
    return sum(arr)

def maximum(arr):
    if len(arr) == 0:
        return None
    return max(arr)

def main():
    n = int(input("Enter the number of elements in the array (n): "))
    arr = []
    
    for i in range(n):
        num = int(input(f"Enter integer {i + 1}: "))
        arr.append(num)
    
    sum_result = summation(arr)
    max_result = maximum(arr)
    
    print(f"Sum of the array elements: {sum_result}")
    print(f"Maximum element in the array: {max_result}")

if __name__ == "__main__":
    main()
