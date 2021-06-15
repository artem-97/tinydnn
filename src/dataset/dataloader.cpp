#include "dataloader.h"

Dataloader::Dataloader(const Dataset& dataset, int batch_size)
    : dataset_(dataset), batch_size_(batch_size) {}
