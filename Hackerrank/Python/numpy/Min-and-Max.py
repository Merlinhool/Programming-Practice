import numpy
n, m = map(int, input().split())
mtx = numpy.array([list(map(int, input().split())) for i in range(n)])
print(numpy.max(numpy.min(mtx, axis =  1)))
