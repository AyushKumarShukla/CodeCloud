import sys
def abs_only(seq):
    for val in seq:
        if val >= 0:
            yield val

seq = [int(arg) for arg in sys.argv[1:]]

absseq=list(abs_only(seq))
print(absseq)

