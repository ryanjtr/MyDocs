Github
======

.. contents::
    :depth: 2

Working space: thư mục chưa code trên máy tính bạn
Stage area và git local

Lệnh
------
    * ``git init`` khởi tạo git local (chỉ dùng lần đầu tiên)
    * ``git add .`` thêm toàn bộ file trong workspace vào stage area
    * ``git commit -m "message"`` commit code lên git local
    * ``git remote add origin <Url_repo>`` liên kết tới remote repo
    * ``git push -u origin master`` đẩy code lên remote, "-u" là nhớ git push origin
    * ``git pull origin master`` cập nhật code từ remote về máy mình, từ lần sau chỉ dùng ``git pull``
    * ``git checkout <commit_id>`` chuyển từ version này sang version khác(verison: các bản code đã commit lên git local)
    * ``git git checkout -b branch`` tạo ra branch1 và chuyển sang nhánh branch1, (-b là để tạo mới một branch)
    * ``git merge branch1`` merge branch1 vào master
    * ``git branch -a`` danh sách các branch
    * ``git reset --hard <id_c2>`` nếu ban đầu có commit c1 c2 c3 c4 c5, nếu dùng lệnh này thì ta quay về code ở c2 và code c3 c4 c5 bị xóa đi và coi như chưa từng tồn tại
    * ``git push -f`` ép push lên remote với lịch sử commmit không trùng khớp (hạn chế dùng)
    * ``git log`` xem id các commit (dùng :Q để thoát log)
    * ``git revert <id_c3>`` nếu ban đầu có commit c1 c2 c3 c4 c5, nếu dùng lệnh này thì ta quay về code ở c2 và code c3 c4 c5 không bị xóa đi và clúc này tạo ra c6. Lấy code của commit trước cái id_commit mà mình nhập   

.. note::
    Nếu lần đầu sử dụng git thì phải gõ 2 lệnh sau trước khi commit
    * ``git config --global user.name "John"``
    * ``git config --global user.mail "nguyevana@gmail.com"``
    * ``git config credential.helper store`` lưu account vào máy, để các lần sau nó không hỏi password nữa

