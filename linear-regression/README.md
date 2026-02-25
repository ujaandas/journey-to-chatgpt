# Linear Regression

Given a set of points, how can we draw a line that passes as close to these
points as possible? First, we need to answer some important questions:
- Do these points roughly look like they form a line?
- What do we mean by "points that roughly look like they form a line?"
- How do we find such a line?
- How and why is this useful in the real world?
- Why is this "machine learning"?

## Predicting the Price of a House
Given a simple set of houses, where a 1-bedroom house would cost 150$, and each
additional room would add $50 more, we can define the price of a house as:

$$
Price = 100 + 50(Number of rooms)
$$

In this context, our formula gives us a *prediction* of the price of the house,
based on the *feature*, which is the number of rooms. The price per room is
called the *weight* of that corresponding feature, and the base price is called
the *bias* of the model.

- **Feature:** The features of a data point are those properties that we use to
  make our prediction.
- **Labels:** This is the target that we try to predict from the features.
- **Model:** A machine learning model is essentially a formula, which predicts a
  label from a set of features.
- **Prediction:** The prediction is the output of the model.
- **Weights:** In the formula corresponding to the model, each feature is
  multiplied by a corresponding factor.
- **Bias:** The bias is any constant that the formula corresponding to the model
  refers to, that is not intrinsically attached to any of the features.


