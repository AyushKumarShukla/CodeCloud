import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression

data_root = "https://github.com/ageron/data/raw/main/"
sat = pd.read_csv(data_root + "lifesat/lifesat.csv")

gdp = sat[["GDP per capita (USD)"]].values
countrysat = sat[["Life satisfaction"]].values

sat.plot(kind="scatter", grid=True, x="GDP per capita (USD)", y="Life satisfaction");
plt.axis([23_500,62_500,4,9])

model = LinearRegression()

model.fit(gdp,countrysat)

new_values = np.linspace(gdp.min(),gdp.max(),100).reshape(-1,1)
predictions = model.predict(new_values)

plt.plot(new_values,predictions,color="blue",linewidth=2, label="Predictions")
plt.show()
