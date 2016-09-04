import numpy

def getInt():
    return map(int, input().split())

n, m, p = getInt()
mtx1 = numpy.array([list(getInt()) for i in range(n)])
mtx2 = numpy.array([list(getInt()) for i in range(m)])
print(numpy.concatenate((mtx1, mtx2)))
