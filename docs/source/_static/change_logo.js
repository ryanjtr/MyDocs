document.addEventListener("DOMContentLoaded", function() {
    setTimeout(function() {
        var logo = document.querySelector("img#logo");
        if (logo) {
            logo.src = "_static/couplestitch.gif"; // Đường dẫn tới logo mới của bạn
        }
    }, 5000); // Thay đổi logo sau 5 giây
});
