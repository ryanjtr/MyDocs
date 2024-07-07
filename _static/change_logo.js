document.addEventListener("DOMContentLoaded", function() {
    var logo = document.querySelector(".wy-side-nav-search .logo");
    if (logo) {
        var logos = ['_static/stitch.gif', '_static/c_stitch.gif','_static/sad_stitch.gif','_static/love_stitch.gif']; // Danh sách các logo
        var currentIndex = 0; // Index của logo hiện tại

        setInterval(function() {
            currentIndex = (currentIndex + 1) % logos.length;
            logo.src = logos[currentIndex];
        }, 5000); // Thay đổi logo sau mỗi 5 giây
    }
});
