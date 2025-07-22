Github 
=======

.. contents::
    :depth: 3

Introduction
------------

This guide provides a step-by-step process for using Git and GitHub, from installation to managing repositories, branches, and commits. It is designed for beginners and intermediate users, covering essential commands and common workflows.

Prerequisites
-------------

Before starting, ensure you have:
- A GitHub account (sign up at `GitHub <https://github.com>`_).
- Git installed on your system.
- Basic familiarity with the command line.

Installing Git
--------------

**For Ubuntu**

.. code-block:: bash

    sudo apt install git

**For Windows**

- **Windows**: Download and install Git from `git-scm.com <https://git-scm.com>`_.


Verify installation:

.. code-block:: bash

    git --version

Configuring Git
----------------

Set up your Git identity (run these commands once):

.. code-block:: bash

    git config --global user.name "Your Name"
    git config --global user.email "your.email@example.com"

To store credentials for convenience:

.. code-block:: bash

    git config --global credential.helper store

.. note::

    The ``credential.helper store`` command saves your GitHub credentials locally, so you don't need to re-enter them for each push. Use with caution on shared computers.

Creating a GitHub Repository
----------------------------

1. Log in to your GitHub account.
2. Click the **+** icon in the top-right corner and select **New repository**.
3. Provide a repository name, description (optional), and choose visibility (public/private).
4. Optionally, initialize with a README, .gitignore, or license.
5. Click **Create repository** to generate the repository URL (e.g., ``https://github.com/username/repo.git``).

Initializing a Local Repository
---------------------------------

Navigate to your project directory:

.. code-block:: bash

    cd /path/to/your/project

Initialize a local Git repository:

.. code-block:: bash

    git init

.. note::

    If you accidentally initialize a repository in the wrong folder:
    - On Windows, list hidden files with ``dir /a`` to find the ``.git`` folder, then delete it with ``rmdir /s /q .git``.
    - On Linux/Mac, use ``ls -a`` to find ``.git``, then delete with ``rm -rf .git``.

Ignoring Files with .gitignore
--------------------------------

Create a ``.gitignore`` file to exclude files/folders from being tracked (e.g., logs, temporary files):

.. code-block:: bash

    touch .gitignore

Example ``.gitignore`` content:

.. code-block:: text

    # Ignore all .log files
    *.log
    # Except specific log file
    !important.log
    # Ignore entire folder
    web-app/*

If a file/folder is already tracked, remove it from Git's index:

.. code-block:: bash

    git rm -r --cached <folder_or_file>
    git commit -m "Update .gitignore to ignore <folder_or_file>"

Staging and Committing Changes
-------------------------------

Stage all changes:

.. code-block:: bash

    git add .

Commit changes with a message:

.. code-block:: bash

    git commit -m "Descriptive commit message"

View commit history:

.. code-block:: bash

    git log

Linking to a Remote Repository
--------------------------------

Connect your local repository to the GitHub repository:

.. code-block:: bash

    git remote add origin <repository_url>

Verify the remote:

.. code-block:: bash

    git remote -v

Pushing to GitHub
-----------------

Push changes to the ``main`` branch (or ``master`` in older repositories):

.. code-block:: bash

    git push -u origin main

.. note::

    The ``-u`` flag sets the upstream branch, so subsequent pushes can use simply ``git push``.

Pulling Updates from GitHub
----------------------------

Update your local repository with changes from the remote branch:

.. code-block:: bash

    git pull origin main

Working with Branches
---------------------

**List Branches**

View all local and remote branches:

.. code-block:: bash

    git branch -a

**Create and Switch to a New Branch**

.. code-block:: bash

    git checkout -b <branch_name>

.. note::

    For Git 2.23+, you can use ``git switch -c <branch_name>`` to create and switch to a branch.

**Switch to an Existing Branch**

.. code-block:: bash

    git checkout <branch_name>

Or with Git 2.23+:

.. code-block:: bash

    git switch <branch_name>

**Merge a Branch**

Switch to the target branch (e.g., ``main``) and merge another branch:

.. code-block:: bash

    git checkout main
    git merge <branch_name>

**Delete a Branch**

Delete a local branch:

.. code-block:: bash

    git branch -d <branch_name>

Delete a remote branch:

.. code-block:: bash

    git push origin --delete <branch_name>

.. note::

    Use ``-D`` instead of ``-d`` to force-delete a local branch with unmerged changes.

Cloning a Repository
--------------------

Clone a repository to your local machine:

.. code-block:: bash

    git clone <repository_url>

For a shallow clone (only the latest state):

.. code-block:: bash

    git clone --recurse-submodules --depth 1 <repository_url>

Managing Commits
----------------

**Revert to a Previous Commit**

Undo changes by reverting to a specific commit:

.. code-block:: bash

    git revert <commit_id>

**Reset to a Previous Commit**

Reset to a previous commit, discarding later commits:

.. code-block:: bash

    git reset --hard <commit_id>

.. warning::

    Use ``git reset --hard`` cautiously, as it permanently deletes commits after the specified ID.

Soft reset (keeps changes in working directory):

.. code-block:: bash

    git reset --soft <commit_id>

**Force Push**

Force push to overwrite remote commit history (use with caution):

.. code-block:: bash

    git push -f

Restoring Files
---------------

**Restore a Specific File**

Revert a modified but uncommitted file to its last committed state:

.. code-block:: bash

    git checkout -- <file_name>

Or with Git 2.23+:

.. code-block:: bash

    git restore <file_name>

**Restore All Files**

Revert all uncommitted changes:

.. code-block:: bash

    git checkout .
    # Or
    git restore .

Reset Local Repository to Match Remote
----------------------------------------

Fetch the latest remote state and reset local repository:

.. code-block:: bash

    git fetch origin
    git reset --hard origin/<branch_name>

Cleaning Untracked Files
--------------------------

Remove untracked files and directories:

.. code-block:: bash

    git clean -df

Troubleshooting
---------------

**Write Access Denied**

If you encounter: *Write access to repository not granted. fatal: unable to access*

- Ensure you have write permissions for the repository.
- Check your credentials or SSH key configuration.
- Refer to this `StackOverflow thread <https://stackoverflow.com/questions/70538793/remote-write-access-to-repository-not-granted-fatal-unable-to-access>`_ for detailed solutions.

**Detached HEAD State**

If you checkout a specific commit (e.g., ``git checkout <commit_id>``), you enter a detached HEAD state. To save changes:

1. Create a new branch:

.. code-block:: bash

    git checkout -b new-branch-name

2. Commit changes and push as usual.

Additional Commands
-------------------

**List Files in Current Branch**

.. code-block:: bash

    git ls-files

**Check Current Branch**

.. code-block:: bash

    git branch

Conclusion
----------

This guide covers the essential Git and GitHub workflows for managing repositories, branches, and commits. Practice these commands in a test repository to build confidence before applying them to critical projects. For further details, refer to the `Git documentation <https://git-scm.com/doc>`_ or `GitHub Docs <https://docs.github.com>`_.