# Linear Regression
Given a set of points, how can we draw a line that passes as close to these
points as possible? First, we need to answer some important questions:
- Do these points roughly look like they form a line?
- What do we mean by "points that roughly look like they form a line?"
- How do we find such a line?
- How and why is this useful in the real world?
- Why is this "machine learning"?

## Predicting the Price of a House 1
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

## Predicting the Price of a House 2
So now, what if we had a more complicated dataset? We'll start with the same
dataset as before, but add a small variance of +/- [0-10] to each value. Now,
our equation becomes a little more complicated. It might look like this:

$$
Price = 100 + 50(Number of rooms) + (Small error)
$$

## Multivariate Linear Regression
Okay, so our previous model predicted the price of a house based on a single
feature, the number of rooms. But in reality, there are many _other_ factors
that influence price, such as size, quality of schools, age of the house, etc...

Actually, it's quite easy. Similar to how we had a weight multiplying a feature,
we just add new ones for each feature! Thus, our new model might look like this:

$$
Price = 30(Number of rooms) + 1.5(Size) + 10(Quality of schools) - 2(Age of
house) + 50
$$

> If you're wondering why we _subtract_ the "Age of house" feature, it's because
> we expect the house to _drop_ as its age increases. In other words, they are
> _negatively_ correlated, whereas all the other features are _positively_
> correlated.

## The Linear Regression Algorithm
Given a dataset of points on a plane, we want to generate a line that passes
close to the points.

Geometrically speaking, we do this by:
1. Pick a random line.
2. Pick a random data point.
3. Move the line a little closer to that point.
4. Repeat steps 2-3 many, many, MANY times.
5. Return our line.

Mathematically speaking, this is equivalent to:
1. Pick a model with random weights (for each feature) and a random bias.
2. Pick a random data point.
3. Slightly adjust the weights and bias to improve the prediction for that
   particular data point.
4. Repeat steps 2-3 many, many, MANY times.
5. Return our model.

So okay, sure. Not too bad. But all of that's a lot easier said than done. The
hardest and least intuitive step is 3; moving the "line" closer to a point is
easy on graph paper, but not as much on a computer.

### The Naiive Approach

The naiive approach to move our line is as follows:

Given a line with slope $m$, $y$-intercept $b$, and equation $\hat{p} = mr + b$,
as well as coordinates $(r, p)$, such that we want a new line $\hat{p} = m'r +
b$ that is _closer_ to that point.

Given two, very small random numbers $n_1$ and $n_2$, we essentially want to add
these numbers to the slope $m$ and $y$-intercept $b$, respectively. 

We have four possible cases:

- Case 1: If the point is above the line and to the right of the $y$-axis, we
  rotate the line counter-clockwise and translate it upwards.
- Case 2: If the point is above the line and to the left of the $y$-axis, we
  rotate the line clockwise and translate it upwards.
- Case 3: If the point is below the line and to the right of the $y$-axis, we
  rotate the line clockwise and translate it downwards.
- Case 4: If the point is below the line and to the left of the $y$-axis, we
  rotate the line counter-clockwise and translate it downwards.


### The Square Trick

There is another way to do what we just did! For what it's worth, the above
"naiive" approach is quite simple, there are only four conditions that were
based on the position of the point relative to the line. However, the square
trick can bring these four cases down to just one by finding values with correct
signs to add to the slope and $y$-intercept to _always_ move the line closer to
our point.

Looking at the $y$-intercept, note that depending on if the point is above or
below the line, we either add or subtract a small amount, respectively. Thus, if a
point is above the line, $p-\hat{p}$ is positive, and vice versa. Therefore, if
we add the difference $p-\hat{p}$ to the $y$-intercept, the line will _always_
move towards the point. THis is because this value is positive when the point is
above the line, and negative when below. However, we need to be careful to take
small steps, and therefore introduce a new term, *learning rate*.

**Learning Rate:** A very small number that we pick before training our model,
and helps us make sure our model changes in very, very small amounts by
training.

Similar to the above, we can look at the slope. When the point is either above
the line and right of the $y$-axis, OR below the line and left of the $y$-axis,
we rotate the line counter-clockwise. Otherwise, we rotate it clockwise. If a
point $(r, p)$ is right of the $y$-axis, then $r$ is positive. If it's to the
left of the $y$-axis, then $r$ is negative. 

Now consider the value of $r(p - \hat{p}$. This is positive when both $r$ and
$p-\hat{p}$ are both positive or both negative, ie; it lines up perfectly with
cases 1/4, or 2/3, respectively. Therefore, we, like before, just add 
$r(p-\hat{p}$ times the learning rate, of course.
