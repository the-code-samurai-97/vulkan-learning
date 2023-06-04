
#  vulkan learning 

### Description
learning the vulkan library  using C++ and bazel build 

### linux Installation
#### 1.vulkan libraries
```
sudo apt install vulkan-tools
sudo apt install libvulkan-dev
sudo apt install vulkan-validationlayers-dev spirv-tools
``` 
#### 2.Bazel
```
sudo apt install apt-transport-https curl gnupg -y
```
```
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg  
```
```
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
```
```
sudo apt update && sudo apt install bazel
bazel --version
``` 
### References
    https://vulkan-tutorial.com/en/
    https://bazel.build/install/ubuntu

### Build
```
cd vulkan-learning
bazel build //...
bazel run code:1_vulkan_window