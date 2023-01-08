<div id="top">
# Navvy-Man
Navvy Man is a fun C language game built with easyX. Players navigate through challenges and obstacles to reach their destination. I completed this project in my freshman year
</div>

## Demonstration Video
<div align="center">
   <a href="https://youtu.be/vbmYn1qS_FU">
   <img src="https://github.com/vincezh2000/Navvy-Man/blob/main/Navvy_logo.jpg" width="600" />
   </a>
</div>

<p align="right">(<a href="#top">back to top</a>)</p>


////////



## Table of Contents
<ul>
 <li><a href="#Why-Colossal-AI">Why Colossal-AI</a> </li>
 <li>
   <a href="#Parallel-Training-Demo">Parallel Training Demo</a>
   <ul>
     <li><a href="#GPT-3">GPT-3</a></li>
     <li><a href="#Recommendation-System-Models">Recommendation System Models</a></li>
   </ul>
 </li>
<ul> 



## Features

Colossal-AI provides a collection of parallel components for you. We aim to support you to write your
distributed deep learning models just like how you write your model on your laptop. We provide user-friendly tools to kickstart
distributed training and inference in a few lines.

- Parallelism strategies
  - Data Parallelism
  - Pipeline Parallelism
  - 1D, [2D](https://arxiv.org/abs/2104.05343), [2.5D](https://arxiv.org/abs/2105.14500), [3D](https://arxiv.org/abs/2105.14450) Tensor Parallelism
  - [Sequence Parallelism](https://arxiv.org/abs/2105.13120)
  - [Zero Redundancy Optimizer (ZeRO)](https://arxiv.org/abs/1910.02054)
  - [Auto-Parallelism](https://github.com/hpcaitech/ColossalAI/tree/main/examples/language/gpt/auto_parallel_with_gpt)

- Heterogeneous Memory Management
  - [PatrickStar](https://arxiv.org/abs/2108.05818)

- Friendly Usage
  - Parallelism based on configuration file

- Inference
  - [Energon-AI](https://github.com/hpcaitech/EnergonAI)

- Colossal-AI in the Real World
  - Biomedicine: [FastFold](https://github.com/hpcaitech/FastFold) accelerates training and inference of AlphaFold protein structure
<p align="right">(<a href="#top">back to top</a>)</p>

## Parallel Training Demo

### GPT-3
<p align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/GPT3-v5.png" width=700/>
</p>

- Save 50% GPU resources, and 10.7% acceleration

### GPT-2
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/GPT2.png" width=800/>

- 11x lower GPU memory consumption, and superlinear scaling efficiency with Tensor Parallelism

<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/(updated)GPT-2.png" width=800>

- 24x larger model size on the same hardware
- over 3x acceleration
### BERT
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/BERT.png" width=800/>

- 2x faster training, or 50% longer sequence length

### PaLM
- [PaLM-colossalai](https://github.com/hpcaitech/PaLM-colossalai): Scalable implementation of Google's Pathways Language Model ([PaLM](https://ai.googleblog.com/2022/04/pathways-language-model-palm-scaling-to.html)).

### OPT
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/OPT_update.png" width=800/>

- [Open Pretrained Transformer (OPT)](https://github.com/facebookresearch/metaseq), a 175-Billion parameter AI language model released by Meta, which stimulates AI programmers to perform various downstream tasks and application deployments because public pretrained model weights.
- 45% speedup fine-tuning OPT at low cost in lines. [[Example]](https://github.com/hpcaitech/ColossalAI-Examples/tree/main/language/opt) [[Online Serving]](https://service.colossalai.org/opt)

Please visit our [documentation](https://www.colossalai.org/) and [examples](https://github.com/hpcaitech/ColossalAI-Examples) for more details.

### ViT
<p align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/ViT.png" width="450" />
</p>

- 14x larger batch size, and 5x faster training for Tensor Parallelism = 64

### Recommendation System Models
- [Cached Embedding](https://github.com/hpcaitech/CachedEmbedding), utilize software cache to train larger embedding tables with a smaller GPU memory budget.

<p align="right">(<a href="#top">back to top</a>)</p>

## Single GPU Training Demo

### GPT-2
<p id="GPT-2-Single" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/GPT2-GPU1.png" width=450/>
</p>

- 20x larger model size on the same hardware

<p id="GPT-2-NVME" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/GPT2-NVME.png" width=800/>
</p>

- 120x larger model size on the same hardware (RTX 3080)

### PaLM
<p id="PaLM-Single" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/PaLM-GPU1.png" width=450/>
</p>

- 34x larger model size on the same hardware

<p align="right">(<a href="#top">back to top</a>)</p>


## Inference (Energon-AI) Demo

<p id="GPT-3-Inference" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/inference_GPT-3.jpg" width=800/>
</p>

- [Energon-AI](https://github.com/hpcaitech/EnergonAI): 50% inference acceleration on the same hardware

<p id="OPT-Serving" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/OPT_serving.png" width=800/>
</p>

- [OPT Serving](https://service.colossalai.org/opt): Try 175-billion-parameter OPT online services for free, without any registration whatsoever.

<p id="BLOOM-Inference" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/BLOOM%20Inference.PNG" width=800/>
</p>

- [BLOOM](https://github.com/hpcaitech/EnergonAI/tree/main/examples/bloom): Reduce hardware deployment costs of 175-billion-parameter BLOOM by more than 10 times.

<p align="right">(<a href="#top">back to top</a>)</p>

## Colossal-AI in the Real World

### AIGC
Acceleration of AIGC (AI-Generated Content) models such as [Stable Diffusion v1](https://github.com/CompVis/stable-diffusion) and [Stable Diffusion v2](https://github.com/Stability-AI/stablediffusion).
<p id="diffusion_train" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/Stable%20Diffusion%20v2.png" width=800/>
</p>

- [Training](https://github.com/hpcaitech/ColossalAI/tree/main/examples/images/diffusion): Reduce Stable Diffusion memory consumption by up to 5.6x and hardware cost by up to 46x (from A100 to RTX3060).

<p id="diffusion_demo" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/DreamBooth.png" width=800/>
</p>

- [DreamBooth Fine-tuning](https://github.com/hpcaitech/ColossalAI/tree/main/examples/images/dreambooth): Personalize your model using just 3-5 images of the desired subject.

<p id="inference" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/Stable%20Diffusion%20Inference.jpg" width=800/>
</p>

- [Inference](https://github.com/hpcaitech/ColossalAI/tree/main/examples/images/diffusion): Reduce inference GPU memory consumption by 2.5x.


<p align="right">(<a href="#top">back to top</a>)</p>

### Biomedicine
Acceleration of [AlphaFold Protein Structure](https://alphafold.ebi.ac.uk/)

<p id="FastFold" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/FastFold.jpg" width=800/>
</p>

- [FastFold](https://github.com/hpcaitech/FastFold): accelerating training and inference on GPU Clusters, faster data processing, inference sequence containing more than 10000 residues.

<p id="xTrimoMultimer" align="center">
<img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/xTrimoMultimer_Table.jpg" width=800/>
</p>

- [xTrimoMultimer](https://github.com/biomap-research/xTrimoMultimer): accelerating structure prediction of protein monomers and multimer by 11x.


<p align="right">(<a href="#top">back to top</a>)</p>

## Installation

### Download From Official Releases

You can visit the [Download](https://www.colossalai.org/download) page to download Colossal-AI with pre-built CUDA extensions.


### Download From Source

> The version of Colossal-AI will be in line with the main branch of the repository. Feel free to raise an issue if you encounter any problem. :)

```shell
git clone https://github.com/hpcaitech/ColossalAI.git
cd ColossalAI

# install dependency
pip install -r requirements/requirements.txt

# install colossalai
pip install .
```

By default, we do not compile CUDA/C++ kernels. ColossalAI will build them during runtime.
If you want to install and enable CUDA kernel fusion (compulsory installation when using fused optimizer):

```shell
CUDA_EXT=1 pip install .
```

<p align="right">(<a href="#top">back to top</a>)</p>

## Use Docker

### Pull from DockerHub

You can directly pull the docker image from our [DockerHub page](https://hub.docker.com/r/hpcaitech/colossalai). The image is automatically uploaded upon release.


### Build On Your Own

Run the following command to build a docker image from Dockerfile provided.

> Building Colossal-AI from scratch requires GPU support, you need to use Nvidia Docker Runtime as the default when doing `docker build`. More details can be found [here](https://stackoverflow.com/questions/59691207/docker-build-with-nvidia-runtime).
> We recommend you install Colossal-AI from our [project page](https://www.colossalai.org) directly.


```bash
cd ColossalAI
docker build -t colossalai ./docker
```

Run the following command to start the docker container in interactive mode.

```bash
docker run -ti --gpus all --rm --ipc=host colossalai bash
```

<p align="right">(<a href="#top">back to top</a>)</p>

## Community

Join the Colossal-AI community on [Forum](https://github.com/hpcaitech/ColossalAI/discussions),
[Slack](https://join.slack.com/t/colossalaiworkspace/shared_invite/zt-z7b26eeb-CBp7jouvu~r0~lcFzX832w),
and [WeChat](https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/WeChat.png "qrcode") to share your suggestions, feedback, and questions with our engineering team.

## Contributing

If you wish to contribute to this project, please follow the guideline in [Contributing](./CONTRIBUTING.md).

Thanks so much to all of our amazing contributors!

<a href="https://github.com/hpcaitech/ColossalAI/graphs/contributors"><img src="https://raw.githubusercontent.com/hpcaitech/public_assets/main/colossalai/img/contributor_avatar.png" width="800px"></a>

*The order of contributor avatars is randomly shuffled.*

<p align="right">(<a href="#top">back to top</a>)</p>


## Cite Us

```
@article{bian2021colossal,
  title={Colossal-AI: A Unified Deep Learning System For Large-Scale Parallel Training},
  author={Bian, Zhengda and Liu, Hongxin and Wang, Boxiang and Huang, Haichen and Li, Yongbin and Wang, Chuanrui and Cui, Fan and You, Yang},
  journal={arXiv preprint arXiv:2110.14883},
  year={2021}
}
```

<p align="right">(<a href="#top">back to top</a>)</p>