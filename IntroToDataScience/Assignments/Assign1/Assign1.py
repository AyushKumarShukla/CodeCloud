import pandas as pd
pd.set_option('display.max_columns', None)
pd.set_option('display.width', None)
pd.set_option('display.max_rows', 1000)

df = pd.read_csv("C:\\Users\\HP\\Downloads\\WorldBankData\\India.csv", skiprows=4)

df.head(1000).to_csv("preview.csv", index=False)

