# How to train/test Frustum-Pointnets? Repo:https://github.com/charlesq34/frustum-pointnets
## Starting the docker container
Start the docker container from inside the voxelnet folder(`/media/ssd2/archive/ayush/voxelnet`) because the dockerfile is located in `{voxelnet_path}/Dockerfiles`. Here's an example command on how to do it:
``` docker run --gpus '"device=0"'  --mount type=bind,source=$(pwd),target=$(pwd) -w $(pwd) -it tensorflow/tensorflow:latest-gpu bash```
##### Note: device=0 specifies that gpu 0 should be used.(You can choose to use 1 or both.)

## Running startup.sh
This shell script is responsible for running all the necessary commands to install the dependencies, setup the environment etc.

```
cd frustum_pointnets
chmod +x startup.sh
./startup.sh
```
##### Note: You might get hashsum mismatch error while downloading some packages. One easy way to fix is this by re-running startup.sh. After a few tries, it generally works.
## Training (from inside the frustum_pointnets folder)
```sh scripts/command_train_v1.sh```

## Testing:
``` sh scripts/command_test_v1.sh ``` 
## TODO:
The problem with Frustum_PointNets is that the error is too large.(much more than the error mentioned in the research papers) Maybe, there is something wrong with the implementation. Have a look and see if all of the steps mentioned in the github repo are followed correctly. 
