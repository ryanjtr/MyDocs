<script>
    document.addEventListener("DOMContentLoaded", function () {
        var musicControl = document.getElementById("music-control");
    var audio = new Audio('path/to/your/music/file.mp3'); // Đường dẫn đến file nhạc

    musicControl.addEventListener("change", function () {
            if (musicControl.checked) {
        audio.play();
            } else {
        audio.pause();
    audio.currentTime = 0; // Reset lại thời gian phát nhạc khi tắt
            }
        });
    });
</script>
