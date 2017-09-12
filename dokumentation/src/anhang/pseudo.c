// Setup
if |S1| < |S2|
	S <- S1
	T <- S2
else
	S <- S2
	T <- S1
end

for each s from S with |s| >= 5
	i <- intern(s)
	Q <- 5grams(s)
	for each q from Q
		R(q) <- R(q) u i
	end
end

## Run
while read t from T with |t| >= 5
	Q <- 5grams(t)
	W <- 1

	I <- call zero_interns
	for each q from Q
		for each r from R(q)
			I(r) += W
		end
		W <- W * 2
	end

	J <- call zero_streaks
	max <- 0
	for each s from S with |s| >= 5
		i <- intern(s)
		J(i) <- longest_streak(I(i))
		if (J(i) > max)
			max = J(i)
			M <- {s}
		else if (J(i) == max)
			M <- M u s
		end
	end

	## Optional max check
	if (max < |t| / 2)
		continue
	end

	## Output
	for each s from M:
		output s, t, max
	end
end
