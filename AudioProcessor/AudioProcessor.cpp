//implementation of the class AudioProcessor

#include "AudioProcessor.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<short> AudioProcessor::Compress(const vector<short> & audio, short threshold, float rate){
    if (threshold < 0 || rate < 1)
        throw invalid_argument("invalid arguments specified");
    if (audio.size() == 0)
        return {};
    vector<short> compressed (audio.size());

    for (int i = 0; i < audio.size(); ++i) {
        if (audio[i] > threshold) {
            compressed[i] = round((audio[i] - threshold) / rate + threshold);
        } else if (abs(audio[i]) > threshold) {
            compressed[i] = round(((abs(audio[i]) - threshold) / rate + threshold) * (-1));
        } else {
            compressed[i] = audio[i];
        }
    }
    return compressed;
}

vector<short> AudioProcessor::CutOutSilence(const vector<short> & audio, short level, int silenceLength){
    if (level<0 || silenceLength<1)
        throw invalid_argument("invalid arguments specified");
    if (audio.size() == 0)
        return {};
    bool nextVal;
    vector<short> noSilence;
    int silencecounter = 0;
    for (int i = 0; i < audio.size(); ++i) {
        if (audio[i] <= level && audio[i] >= level*(-1)){
            silencecounter++;
            if (audio[i+1] <= level && audio[i+1] >= level*(-1) && i+1 != audio.size()){
                nextVal = true;
            } else {
                nextVal = false;
            }
            noSilence.push_back(audio[i]);
            if (silencecounter >= silenceLength && nextVal == false){
                for (int j = 0; j < silencecounter; ++j) {
                    noSilence.pop_back();
                }
                silencecounter = 0;
            }
        } else {
            noSilence.push_back(audio[i]);
            silencecounter = 0;
        }
    }
return noSilence;
}

vector<short> AudioProcessor::StretchTwice(const vector<short> & audio){
    if (audio.size() == 0)
        return {};
    if (audio.size() < 2){
        return audio;
    }
    vector<short> streched;
    float num;
    for (int i = 0; i < audio.size(); i++) {
        streched.push_back (audio[i]);
        if (i != audio.size()-1){
            num = (float(audio[i]) + float(audio[i+1]))/2;
            streched.push_back(round(num));
        }
    }
    return streched;
}

vector<short> AudioProcessor::Normalize(const std::vector<short> & audio, short normalizeTarget){
    if (audio.size() == 0)
        return {};
    vector<short> normalized(audio.size());
    if (normalizeTarget < 1)
        throw invalid_argument("invalid arguments specified");
    int maxVal;
    auto itMax = max_element(begin(audio), end(audio));
    auto itMin = min_element(begin(audio), end(audio));

    maxVal = max(abs(*itMax),abs(*itMin));
    float num = float(normalizeTarget)/maxVal;
    for (int i = 0; i < audio.size(); ++i) {
        normalized[i] = round(audio[i]*num);
    }
    return normalized;
}