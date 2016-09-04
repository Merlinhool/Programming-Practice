import numpy
n, m = map(int, input().split())
mtx = numpy.array([list(map(int, input().split())) for i in range(n)])
print(numpy.mean(mtx, axis = 1))
print(numpy.var(mtx, axis = 0))
print(numpy.std(mtx, axis = None))
