EPSILON = 0.001
DEFAULT_ITER = 20

def kMean(num_of_clusters, iter, input_data):
    iter = check_num_of_iter(iter)
    check_input_data(input_data)

def check_num_of_clusters(num_of_clusters, num_of_datapoints):
    if num_of_clusters <= 1 or num_of_clusters >= num_of_datapoints:
        raise Exception("Invalid number of clusters!")

def check_num_of_iter(num_of_iter):
    if 1 <= num_of_iter or num_of_iter >= 1000:
        raise Exception("Invalid maximum iteration!")
    if num_of_iter == 0 or num_of_iter == None:
        num_of_iter = 20
    
    return iter

def check_input_data(input_data):
    if not input_data.lower().endswith('.txt'):
        raise Exception("NA")
