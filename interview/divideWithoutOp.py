def div(a, b):
    """
    To divide a by b without / operator,
    assuming a >= 0 and b > 0.
    Result floored to the nearest integer.
    """

    c = 0
    d = b
    while True:
        if d > a:
            break
        else:
            c = c + 1
            d = d + b

    return c

for a in range(4, 50):
    print "expected(" + str(a / 2) + ") "+ str(div(a, 2))