
#reading and analysing the csv logging
import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV
df = pd.read_csv("data/alloc_log.csv")

# Convert time to datetime if needed
df['time'] = pd.to_datetime(df['time'])

# Plot allocation sizes over time
plt.figure(figsize=(10, 5))
plt.plot(df['time'], df['size'], marker='o')
plt.title("Memory Allocation Size Over Time")
plt.xlabel("Time")
plt.ylabel("Size (Bytes)")
plt.grid(True)
plt.show()









#predicting new allocation on analysed and trained data 
from sklearn.linear_model import LinearRegression
import numpy as np

# Use index as time step
df['step'] = range(len(df))

# Features: time step, maybe free status later
X = df[['step']]
y = df['size']

model = LinearRegression()
model.fit(X, y)

# Predict next 10 allocations
future_steps = np.array([[i] for i in range(len(df), len(df) + 10)])
predicted_sizes = model.predict(future_steps)

print("Predicted upcoming allocation sizes:", predicted_sizes)

#go and change the my_malloc based on these new prediction 