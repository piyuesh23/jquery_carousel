(function ($) {
  Drupal.behaviors.jqueryCarousel = {
    attach: function (context) {
      $(document).ready(function(){
        var jcarouselSettings = Drupal.settings.jquery_carousel;
        console.log(jcarouselSettings);
        $('.rs-carousel').carousel(jcarouselSettings);
      });
    }
  }
})(jQuery);