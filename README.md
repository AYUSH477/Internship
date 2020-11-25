# How to train/test Voxel-net? Repo: https://github.com/qianguih/voxelnet
## Starting the docker container
Start the docker container from inside the voxelnet folder(`/media/ssd2/archive/ayush/voxelnet`) because the dockerfile is located in `{voxelnet_path}/Dockerfiles`. Here's an example command on how to do it:
``` docker run --gpus '"device=0"'  --mount type=bind,source=$(pwd),target=$(pwd) -w $(pwd) -it tensorflow/tensorflow:latest-gpu bash```
##### Note: device=0 specifies that gpu 0 should be used.(You can choose to use 1 or both.)

## Running startup.sh
This shell script is responsible for running all the necessary commands to install the dependencies, setup the environment etc.

## Training (from inside the voxelnet folder)
```python3 train.py --alpha 1 --beta 10```
#### Note: alpha and beta are hyper-parameters set by the user. Go through the research paper to learn more about how to set them. 

## Testing:
``` python3 test.py -n default ``` 
``` python3 test.py -n pre_trained_car
```
