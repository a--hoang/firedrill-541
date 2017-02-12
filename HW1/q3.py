import random
import collections

def q3a( iterations ):
    x = 0
    for i in range(0, iterations):
        x += random.random()
    return x / iterations

def q3b( iterations ):
    x = 0
    for i in range(0, iterations):
        x += min(random.random(), random.random())
    return x / iterations

def q3c( iterations ):
    x = 0
    for i in range(0, iterations):
        x += max(random.random(), random.random())
    return x / iterations

# To generate CDF, we will "bucket" the readings by rounding to the nearest hundredth between 0 and 2
# After bucketing, we divide # of readings in each bucket by iterations and can graph the cdf with this data
# To get the complementary cdf, invert the data from above
def q3d( iterations ):
    d = {}
    for i in range(0, iterations):
        x = random.random() + random.random()
        x = round(x, 2)
        if d.get(x,None) == None:
            d[x] = 1
        else:
            d[x] += 1
    ordered = collections.OrderedDict(sorted(d.items()))
    temp = 0.0
    for k in ordered:
        ordered[k] += temp
        temp = ordered[k]
        ordered[k] /= iterations
        # This gives cdf of buckets - invert this to get complementary
        ordered[k] = 1 - ordered[k]
    return ordered

def main():
    x1 = q3a (1000000)
    x2 = q3a (1000000)
    x3 = q3b (1000000)
    x4 = q3c (1000000)
    print 'x1 avg: ', x1
    print 'x2 avg: ', x2
    print 'x3 = min(x1, x2): ', x3
    print 'x4 = max(x1, x2) ', x4

    print 'Bucketed X1 + X2 by hundredths place: '
    data = q3d (1000000)
    for k, v in data.iteritems():
        print k,',', v
        # Gives us csv
    # Output:
    # x1 avg:  0.500065045747
    # x2 avg:  0.500372226119
    # x3 = min(x1, x2):  0.333704941038
    # x4 = max(x1, x2)  0.666982540676
    # Bucketed X1 + X2 by hundredths place:
    # (see csv file)

if __name__ == "__main__":
    main()
