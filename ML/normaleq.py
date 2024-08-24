import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import add_dummy_feature
#set seed for generating probability distros
np.random.seed(42)
m = 100
#1...generating training dataset
#generate a column vector via normal distro
X = 2 * np.random.rand(m,1)
#use the above column vector and add Gaussian noise to it
y = 4 + 3*X + np.random.randn(m,1)

#2...training using closed form solution
# add a dummy feature to X
X_dummy = add_dummy_feature(X)

#apply normal equation
theta_best = np.linalg.inv(X_dummy.T @ X_dummy) @ X_dummy.T @ y

#3...making predictions
X_new = np.array([[0],[2]])
X_new_dummy = add_dummy_feature(X_new)
y_predict = X_new_dummy @ theta_best
print(y_predict)

plt.plot(X_new,y_predict)
plt.plot(X,y,"b.")
plt.show()
