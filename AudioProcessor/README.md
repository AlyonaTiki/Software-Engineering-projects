## class AudioProcessor
implemented methods: <br><br>
```vector Compress(const vector & audio, short threshold, float rate)```(returns the compressed version of the given audio) <br>
Example: audio={1, 4, 25, 15, 0, -7, -40, 10} , threshold=10,  rate=1.5 <br>
Output: {1, 4, 20, 13, 0, -7, -30, 10} // values affected by compression: 20, 13, -30 <br>
```vector CutOutSilence(const vector & audio, short level, int silenceLength)``` <br><br>
Example: audio={1, -3, 10, 25, 56, -1, -2, -16, -20, -8, -1, 1, 7, 12}, level=10, silenceLength=3 <br>
Output: {25, 56, -1, -2, -16, -20, 12} <br><br>
```vector StretchTwice(const vector & audio)```(Returns the version of audio where between each pair of original samples from audio an extra sample appears. This extra sample is an average (arithmetic mean) of the two original samples.) <br>
Example: audio={1, 4, 23, -2, -28, 10 } <br>
Output: {1, 3, 4, 14, 23, 11, -2, -15, -28, -9, 10} <br><br>
```vector Normalize(const vector & audio, short normalizeTarget)``` (returns a version of audio where all samples are proportionally increases or decreased to ensure that the largest absolute value from all resulting samples is exactly normalizeTarget) <br>
Example 1: audio={1, 3, -2, 5, -4, 0}  normilizeTarget=10 <br>
Output: {2, 6, -4, 10, -8, 0} <br>
Explanation: all samples from the original audio were multiplied by 2, so that the largest absolute value in the result is 10.
