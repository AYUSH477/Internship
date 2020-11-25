# Preparing the data

First of all, you need the raw dataset like this one: `/media/ssd2/archive/ayush/voxelnet/data/raw (the format of the sub-directories should be the same.)`
Once you have this, run: (from the data folder) 
``` 
python3 crop.py
```

Next, run:
```
python3 organize.py
```
organize.py uses `/media/ssd2/archive/ayush/voxelnet/data/train.txt` and `/media/ssd2/archive/ayush/voxelnet/data/test.txt` to divide the raw data into training and validation set. Once you run the code, they are stored in: `/media/ssd2/archive/ayush/voxelnet/data/training` and `/media/ssd2/archive/ayush/voxelnet/data/validation`
