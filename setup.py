import urllib.request
mnist_train = 'http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz'
with urllib.request.urlopen(mnist_train) as f:
    html = f.read().decode('utf-8')
