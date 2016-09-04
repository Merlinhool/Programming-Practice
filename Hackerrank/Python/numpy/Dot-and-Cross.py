import numpy
n = int(input())
mtx1 = numpy.array([list(map(int, input().split())) for i in range(n)])
mtx2 = numpy.array([list(map(int, input().split())) for i in range(n)])
print(numpy.dot(mtx1, mtx2))
