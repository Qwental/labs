def main():
    tasks = [f'+ task{j}_{i} - TODO'for j in range(1,6) for i in range(1, 11) ]
    
    for x in tasks:
        print(x)


if __name__ == "__main__":
    main()
