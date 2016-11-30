import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""
        self.positive = set()
        self.negative = set()
        
        file = open(positives, "r")
        for line in file:
            if line.find(';'):
                self.positive.add(line.rstrip("\n"))
        file.close()
        file = open(negatives, "r")
        for line in file:
            if line.find(';'):
                self.negative.add(line.rstrip("\n"))
        file.close()        
        # TODO

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text.lower())
        score = 0
        for i in self.positive:
            for j in tokens:
                if j == i:
                    score +=1
        for i in self.negative:
            for j in tokens:
                if j == i:
                    score -=1
        return score            
