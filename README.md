# Polygon

A polygon-utilizing search algorithm.


## Description
This repository contains the source code for a new and potentially useful search algorithm that can be used within graphs (with nodes and edges) to find an optimal path between a starting node and an ending node.

### Rules of Algorithm
1. In an undirected and weighted graph, draw an auxiliary straight line from the starting node to the ending node.

2. Calculate the distance of points from the auxiliary line.

3. Check if a polygon exists (polygons are stored as strings of points).
    - If yes, check if the furthest point's name is in the string.
        - If yes, remove the point and repeat step 4.
        - If not, remove the point and continue with the next furthest point.
    - If not, 
        - Include the recently removed point (P).
        - If there is no recently removed point (no polygons initially), use the point furthest from the imaginary line.
        - Split the graph from the starting node to P, and from P to the ending node.
        - Utilise recursion to find the next crucial points within the two new sub-graphs (repeat step 1 - 4).


## Setup
### Prerequisites
- C++20, g++ compiler
- [Git](https://git-scm.com/downloads)


### Installation
Cloning via HTTPS:

    git clone https://gitlab.com/objected/polygon.git

Cloning via SSH:

    git clone git@gitlab.com:objected/polygon.git

Installing via ZIP folder:
- Download the ZIP archive from the main page and extract it to a folder. 

After installing the project files, remember to change your working directory to the root directory of the project.

    cd polygon

### Execution
To compile and execute the program, run the following commands:

    cd src
    make all
    ./main.out

To clear compiled object and executable files after compilation, run the following command:

    make clean

Other commands available in the Makefile can be shown by running the following command:

    make help


## Contributing
When contributing to this repository, please first discuss the change you wish to make via issue, before making a change. 

Please refer to [CONTRIBUTING.md](./.gitlab/CONTRIBUTING.md) for more information on issues, pull requests, and our code of conduct.

## Acknowledgment
Developed and maintained by:
- [@objecteds](https://github.com/objecteds)


## License
This repository is licensed under the [GNU General Public License v3.0](./LICENSE). 


<!-- 
## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://gitlab.com/objected/polygon.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://gitlab.com/objected/polygon/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Automatically merge when pipeline succeeds](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Test and Deploy

Use the built-in continuous integration in GitLab.

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing(SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

# Editing this README

When you're ready to make this README your own, just edit this file and use the handy template below (or feel free to structure it however you want - this is just a starting point!).  Thank you to [makeareadme.com](https://www.makeareadme.com/) for this template.

## Suggestions for a good README
Every project is different, so consider which of these sections apply to yours. The sections used in the template are suggestions for most open source projects. Also keep in mind that while a README can be too long and detailed, too long is better than too short. If you think your README is too long, consider utilizing another form of documentation rather than cutting out information.

## Name
Choose a self-explaining name for your project.

## Description
Let people know what your project can do specifically. Provide context and add a link to any reference visitors might be unfamiliar with. A list of Features or a Background subsection can also be added here. If there are alternatives to your project, this is a good place to list differentiating factors.

## Badges
On some READMEs, you may see small images that convey metadata, such as whether or not all the tests are passing for the project. You can use Shields to add some to your README. Many services also have instructions for adding a badge.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
Within a particular ecosystem, there may be a common way of installing things, such as using Yarn, NuGet, or Homebrew. However, consider the possibility that whoever is reading your README is a novice and would like more guidance. Listing specific steps helps remove ambiguity and gets people to using your project as quickly as possible. If it only runs in a specific context like a particular programming language version or operating system or has dependencies that have to be installed manually, also add a Requirements subsection.

## Usage
Use examples liberally, and show the expected output if you can. It's helpful to have inline the smallest example of usage that you can demonstrate, while providing links to more sophisticated examples if they are too long to reasonably include in the README.

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.
-->
