# Point-pillars (My progress so far) Repo: https://github.com/tyagi-iiitv/PointPillars
## Starting the docker container
Start the docker container from inside the voxelnet folder(`/media/ssd2/archive/ayush/voxelnet`) because the dockerfile is located in `{voxelnet_path}/Dockerfiles`. Here's an example command on how to do it:
``` docker run --gpus '"device=0"'  --mount type=bind,source=$(pwd),target=$(pwd) -w $(pwd) -it tensorflow/tensorflow:latest-gpu bash```
##### Note: device=0 specifies that gpu 0 should be used.(You can choose to use 1 or both.)

## Running startup.sh
This shell script is responsible for running all the necessary commands to install the dependencies, setup the environment etc.

``` 
cd PointPillars
chmod +x startup.sh
./startup.sh
```
##### Note: You might get hashsum mismatch error while downloading some packages. One easy way to fix is this by re-running startup.sh. After a few tries, it generally works.
## Training (from inside the PointPillars folder)
```python3 point_pillars_training_run.py```

## Testing:
``` python3 point_pillars_prediction.py ```
##### Note: If you get ResourceExhaustedError: OOM when allocating tensor, try testing in parts. Don't test for all of the files at once. For example: You can test for the first 100 validation files, and then the next 100 files and so on till you are done. TIP: Maybe write a shell script to avoid doing it manually. 
## TODO:
1. Convert the output format that you get once you run "point_pillars_prediction.py" to standard Kitti format. 

Once you run point_pillars_prediction.py, you will get something like this in stdout:
``` 
BB | Cls: 1, x: 0.137801, y: -39.895485, l: 0.934592, w: 0.497076, yaw: 1.570796

```
##### Note: The lines starting with BB are the predictions.
Convert it into the standard KITTI format which looks something like this:
``` 
Car 0.0000 0.0000 0.0000 -498.0000 197.0000 -192.0000 284.0000 1.5488 1.6505 3.9668 -20.9586 2.1262 15.9730 -0.9778 0.9836 
```
You can learn more about the KITTI data format here: https://github.com/bostondiditeam/kitti/blob/master/resources/devkit_object/readme.txt 

I tried the solution here but it didn't work: https://github.com/traveller59/second.pytorch/blob/master/second/data/kitti_dataset.py

2. Change the code so that everything gets printed to the respective files instead of stdout.




