import pandas as pd
from sklearn.tree import DecisionTreeRegressor

# Load log file
df = pd.read_csv("data/alloc_log.csv", header=None, names=["event", "size"])

# Keep only allocation rows
df = df[df["event"] == "ALLOC"]
df["step"] = range(len(df))

X = df[["step"]]
y = df["size"]

# Train model
model = DecisionTreeRegressor(max_depth=3)
model.fit(X, y)

# Predict future allocations
future_steps = [[len(df) + i] for i in range(5)]
predictions = model.predict(future_steps)

print("Predicted future allocation sizes:")
for p in predictions:
    print(int(p))
