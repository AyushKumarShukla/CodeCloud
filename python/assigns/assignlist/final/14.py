import sys
def square(x):
    return x*x
seq = [int(arg) for arg in sys.argv[1:]]
squares = list(map(square,seq))
print(f"Input List: {seq}")
print(f"Squared Values: {squares}")
